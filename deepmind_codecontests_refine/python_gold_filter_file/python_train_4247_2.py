import sys

sys.setrecursionlimit(10 ** 6)
int1 = lambda x: int(x) - 1
p2D = lambda x: print(*x, sep="\n")
def II(): return int(sys.stdin.readline())
def MI(): return map(int, sys.stdin.readline().split())
def LI(): return list(map(int, sys.stdin.readline().split()))
def LLI(rows_number): return [LI() for _ in range(rows_number)]
def SI(): return sys.stdin.readline()[:-1]

def main():
    def ok():
        for s,u,row in zip(ss,uu,ans):
            b=row[0]
            if s:
                for a in row[1:]:b|=a
                if b!=u:return False
            else:
                for a in row[1:]:b&=a
                if b!=u:return False
        for t,v,col in zip(tt,vv,zip(*ans)):
            b=col[0]
            if t:
                for a in col[1:]:b|=a
                if b!=v:return False
            else:
                for a in col[1:]:b&=a
                if b!=v:return False
        return True

    mxk=64
    n=II()
    ss=LI()
    tt=LI()
    uu=LI()
    vv=LI()
    # 2進数の各桁ごとに考える
    # bit[k][i][j]...答えのi行j列目のkけた目が入る
    bit=[[[-1]*n for _ in range(n)] for _ in range(mxk)]
    # ORが0⇒その行（または列）はすべて0
    # ANDが1⇒その行（または列）はすべて1
    # と、確定するので、そのマスを埋める
    for i,(s,u) in enumerate(zip(ss,uu)):
        for k in range(mxk):
            if u>>k&1==1-s:
                for j in range(n):bit[k][i][j]=1-s
    for j,(t,v) in enumerate(zip(tt,vv)):
        for k in range(mxk):
            if v>>k&1==1-t:
                for i in range(n):bit[k][i][j]=1-t
    # 確定しなかった（値が初期値-1の）マスについて決めていく
    # ORが1ならば、少なくとも1マスは1が必要
    # ANDが0ならば、少なくとも1マスは0が必要
    for k in range(mxk):
        # -1を含む行と列を調べる
        ii=[]
        jj=[]
        for i,row in enumerate(bit[k]):
            if -1 in row:ii.append(i)
        for j,col in enumerate(zip(*bit[k])):
            if -1 in col:jj.append(j)
        # -1がなければ何もしない
        if not ii:continue
        # 行が1つしかない場合
        # 行の条件を満たすデフォルト値dfを決めておく
        # それぞれの列の条件をみながら、すでに条件を満たしていればデフォルト値を
        # 満たしていなければ、満たすような値を-1と置き換えていく
        if len(ii)==1:
            df=ss[ii[0]]
            for j in jj:
                for i in range(n):
                    if bit[k][i][j]==tt[j]:
                        bit[k][ii[0]][j]=df
                        break
                else:
                    bit[k][ii[0]][j] = tt[j]
        # 列が1つしかない場合
        # 行のときと同じやり方
        elif len(jj) == 1:
            df = tt[jj[0]]
            for i in ii:
                for j in range(n):
                    if bit[k][i][j] == ss[i]:
                        bit[k][i][jj[0]] = df
                        break
                else:
                    bit[k][i][jj[0]] = ss[i]
        # 行も列も2つ以上あるとき
        # すべての行と列に0と1が入るようにすればいい
        else:
            # まず、すべて0にする
            for i in ii:
                for j in jj:
                    bit[k][i][j] = 0
            # 行と列の要素数が違う場合、短い方に付け足して同じ長さにする
            # 付け足すのはどの要素でもいい（今回は先頭にした）
            if len(ii)<len(jj):ii+=[ii[0]]*(len(jj)-len(ii))
            if len(ii)>len(jj):jj+=[jj[0]]*(len(ii)-len(jj))
            # 行と列を同時にずらしながら1を埋める
            # 各行列に最低1つは1を入れていく感じ
            for i,j in zip(ii,jj):
                bit[k][i][j]=1
    #for k in range(mxk):
        #print("k=",k)
        #p2D(bit[k])
    # 各桁をみながら答えを作る
    ans=[[0]*n for _ in range(n)]
    for k in range(mxk):
        for i in range(n):
            for j in range(n):
                ans[i][j]+=bit[k][i][j]<<k
    # 条件を満たしているかの確認
    if ok():
        for row in ans:
            print(*row)
    else:print(-1)

main()