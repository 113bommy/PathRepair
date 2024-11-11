def segfunc(x,y):#自分で設定
    return max(x,y)

def init(init_val):
    #set_val
    for i in range(n):
        seg[i+num-1]=init_val[i]    
    #built
    for i in range(num-2,-1,-1) :
        seg[i]=segfunc(seg[2*i+1],seg[2*i+2]) 
    
def update(k,x):
    k += num-1
    seg[k] = x
    while k:
        k = (k-1)//2
        seg[k] = segfunc(seg[k*2+1],seg[k*2+2])
    
def query(p,q):
    if q<=p:
        return ide_ele
    p += num-1
    q += num-2
    res=ide_ele
    while q-p>1:
        if p&1 == 0:
            res = segfunc(res,seg[p])
        if q&1 == 1:
            res = segfunc(res,seg[q])
            q -= 1
        p = p//2
        q = (q-1)//2
    if p == q:
        res = segfunc(res,seg[p])
    else:
        res = segfunc(segfunc(res,seg[p]),seg[q])
    return res

ide_ele = -1 #単位元 自分で設定してね

N , K = map(int,input().split())
n = 300001
num =2**(300000).bit_length() #num:n以上の最小の2のべき乗
seg=[ide_ele]*2*num
a = [int(input()) for i in range(N)]
dp = [0 for i in range(300001)]
init(dp)

for i in range(N):
    now = query(max(0,a[i]-K),min(300001,a[i]+K+1))+1
    update(a[i],now)

print(query(0,300001))