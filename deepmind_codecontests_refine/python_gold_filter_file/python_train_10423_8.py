import sys,bisect,string,math,time,functools,random,fractions
from heapq import heappush,heappop,heapify
from collections import deque,defaultdict,Counter
from itertools import permutations,combinations,groupby
rep=range
def Golf():n,*t=map(int,open(0).read().split())
def I():return int(input())
def S_():return input()
def IS():return input().split()
def LS():return [i for i in input().split()]
def LI():return [int(i) for i in input().split()]
def LI_():return [int(i)-1 for i in input().split()]
def NI(n):return [int(input()) for i in range(n)]
def NI_(n):return [int(input())-1 for i in range(n)]
def StoLI():return [ord(i)-97 for i in input()]
def ItoS(n):return chr(n+97)
def LtoS(ls):return ''.join([chr(i+97) for i in ls])
def RA():return map(int,open(0).read().split())
def GI(V,E,ls=None,Directed=False,index=1):
    org_inp=[];g=[[] for i in range(V)]
    FromStdin=True if ls==None else False
    for i in range(E):
        if FromStdin:
            inp=LI()
            org_inp.append(inp)
        else:
            inp=ls[i]
        if len(inp)==2:
            a,b=inp;c=1
        else:
            a,b,c=inp
        if index==1:a-=1;b-=1
        aa=(a,c);bb=(b,c);g[a].append(bb)
        if not Directed:g[b].append(aa)
    return g,org_inp
def GGI(h,w,search=None,replacement_of_found='.',mp_def={'#':1,'.':0},boundary=1):
#h,w,g,sg=GGI(h,w,search=['S','G'],replacement_of_found='.',mp_def={'#':1,'.':0},boundary=1) # sample usage
    mp=[boundary]*(w+2);found={}
    for i in range(h):
        s=input()
        for char in search:
            if char in s:
                found[char]=((i+1)*(w+2)+s.index(char)+1)
                mp_def[char]=mp_def[replacement_of_found]
        mp+=[boundary]+[mp_def[j] for j in s]+[boundary]
    mp+=[boundary]*(w+2)
    return h+2,w+2,mp,found
def TI(n):return GI(n,n-1)
def accum(ls):
    rt=[0]
    for i in ls:rt+=[rt[-1]+i]
    return rt
def bit_combination(n,base=2):
    rt=[]
    for tb in range(base**n):s=[tb//(base**bt)%base for bt in range(n)];rt+=[s]
    return rt
def gcd(x,y):
    if y==0:return x
    if x%y==0:return y
    while x%y!=0:x,y=y,x%y
    return y
def show(*inp,end='\n'):
    if show_flg:print(*inp,end=end)
 
YN=['YES','NO'];Yn=['Yes','No']
mo=10**9+7
inf=float('inf')
FourNb=[(-1,0),(1,0),(0,1),(0,-1)];EightNb=[(-1,0),(1,0),(0,1),(0,-1),(1,1),(-1,-1),(1,-1),(-1,1)];compas=dict(zip('WENS',FourNb));cursol=dict(zip('LRUD',FourNb))
l_alp=string.ascii_lowercase
#sys.setrecursionlimit(10**7)
read=sys.stdin.buffer.read
readline=sys.stdin.buffer.readline
input=lambda: sys.stdin.readline().rstrip()


class Tree:
    def __init__(self,inp_size=None,ls=None,init=True,index=1):
        self.LCA_init_stat=False
        self.ETtable=[]
        if init:
            if ls==None:
                self.stdin(inp_size,index=index)
            else:
                self.size=len(ls)+1
                self.edges,_=GI(self.size,self.size-1,ls,index=index)
        return
 
    def stdin(self,inp_size=None,index=1):
        if inp_size==None:
            self.size=int(input())
        else:
            self.size=inp_size
        self.edges,_=GI(self.size,self.size-1,index=index)
        return
    
    def listin(self,ls,index=0):
        self.size=len(ls)+1
        self.edges,_=GI(self.size,self.size-1,ls,index=index)
        return

    def dfs(self,x,func=lambda pr,prv,nx,dist:prv+dist,root_v=0):
        q=deque([x])
        v=[None]*self.size
        v[x]=root_v
        while q:
            c=q.pop()
            for nb,d in self.edges[c]:
                if v[nb]==None:
                    q.append(nb)
                    v[nb]=func(c,v[c],nb,d)
        return v

    def bfs(self,x,func=lambda pr,prv,nx,dist:prv+dist,root_v=0):
        q=deque([x])
        v=[None]*self.size
        v[x]=root_v
        while q:
            c=q.popleft()
            for nb,d in self.edges[c]:
                if v[nb]==None:
                    q.append(nb)
                    v[nb]=func(c,v[c],nb,d)
        return v

    def parent(self,x):
        return self.dfs(0,func=lambda pr,prv,nx,dist:pr,root_v=-1)

    def topological_sort(self,x):  # return topological sort of the tree
        tps=[]
        q=deque([x])
        v=[None]*self.size
        v[x]=0
        while q:
            c=q.popleft()
            tps.append(c)
            for nb,d in self.edges[c]:
                if v[nb]==None:
                    q.append(nb)
                    v[nb]=0
        return tps

    def EulerTour(self,x):
        q=deque()
        q.append(x)
        self.depth=[None]*self.size
        self.depth[x]=0
        self.ETtable=[]
        self.ETdepth=[]
        self.ETin=[-1]*self.size
        self.ETout=[-1]*self.size
        cnt=0
        while q:
            c=q.pop()
            if c<0:
                ce=~c
            else:
                ce=c
                for nb,d in self.edges[ce]:
                    if self.depth[nb]==None:
                        q.append(~ce)
                        q.append(nb)
                        self.depth[nb]=self.depth[ce]+1
            self.ETtable.append(ce)
            self.ETdepth.append(self.depth[ce])
            if self.ETin[ce]==-1:
                self.ETin[ce]=cnt
            else:
                self.ETout[ce]=cnt
            cnt+=1
        return
    
    def LCA_init(self,root):
        self.EulerTour(root)
        self.st=SparseTable(self.ETdepth,init_func=min,init_idl=inf)
        #self.st=SegTree(self.size*2-1,self.ETdepth,function=min,ide=inf)
        self.LCA_init_stat=True
        return
    
    def LCA(self,root,x,y):
        if self.LCA_init_stat==False:
            self.LCA_init(root)
        xin,xout=self.ETin[x],self.ETout[x]
        yin,yout=self.ETin[y],self.ETout[y]
        a=min(xin,yin)
        b=max(xout,yout,xin,yin)
        id_of_min_dep_in_et=self.st.query_id(a,b+1)
        return self.ETtable[id_of_min_dep_in_et]

    def __str__(self):
        return  str(self.edges)

    def show(self):
        if all([all([d==1 for nd,d in edge]) for edge in self.edges]):
            print( [[nd for nd,d in edge] for edge in self.edges] )
        else:
            print(self)

class SparseTable: # O(N log N) for init, O(1) for query(l,r)
    def __init__(self,ls,init_func=min,init_idl=float('inf')):
        self.func=init_func
        self.idl=init_idl
        self.size=len(ls)
        self.N0=self.size.bit_length()
        self.table=[ls[:]]
        self.index=[list(range(self.size))]
        self.lg=[0]*(self.size+1)
        
        for i in range(2,self.size+1):
            self.lg[i]=self.lg[i>>1]+1
 
        for i in range(self.N0):
            tmp=[self.func(self.table[i][j],self.table[i][min(j+(1<<i),self.size-1)]) for j in range(self.size)]
            tmp_id=[self.index[i][j] if self.table[i][j]==self.func(self.table[i][j],self.table[i][min(j+(1<<i),self.size-1)]) else self.index[i][min(j+(1<<i),self.size-1)] for j in range(self.size)]
            self.table+=[tmp]
            self.index+=[tmp_id]
    
    # return func of [l,r)
    def query(self,l,r):
        if r>self.size:r=self.size
        #N=(r-l).bit_length()-1
        N=self.lg[r-l]
        return self.func(self.table[N][l],self.table[N][max(0,r-(1<<N))])
    
    # return index of which val[i] = func of v among [l,r)
    def query_id(self,l,r):
        if r>self.size:r=self.size
        #N=(r-l).bit_length()-1
        N=self.lg[r-l]
        a,b=self.index[N][l],self.index[N][max(0,r-(1<<N))]
        if self.table[0][a]==self.func(self.table[N][l],self.table[N][max(0,r-(1<<N))]):
            b=a
        return b
    
    # return boundary index of r such that func({table[i]} =< x , i in [pos,r]
    def right_bound(self,pos,x):
        k=(self.size-pos).bit_length()
        for j in range(k)[::-1]:
            nx=pos+(1<<j)
            if nx<n and self.query(pos,nx+1)<=x:
                pos+=(1<<j)
        return pos
    
    # return boundary index of l such that func({table[i]} =< x , i in [l,pos]
    def left_bound(self,pos,x):
        k=pos.bit_length()
        for j in range(k)[::-1]:
            nx=pos-(1<<j)
            if 0<=nx and self.query(nx,pos+1)<=x:
                pos-=(1<<j)
        return pos

    def __str__(self):
        return str(self.table[0])
 
    def print(self):
        for i in self.table:
            print(*i)


show_flg=False
show_flg=True
ans=0



def bfs(edge,st):
    n=len(edge)
    q=deque([st])
    v=[-1]*n
    v[st]=0
    while q:
        cur=q.popleft()
        for nx,_ in edge[cur]:
            if v[nx]==-1:
                v[nx]=v[cur]+1
                q.append(nx)
    return v

show_flg=False
show_flg=True
ans=0


n=I()
s=input()+'S'
lst=None
gs=[]
l=0
last=None
for i in range(n+1):
    c=s[i]
    if c=='G':
        l+=1
        e=i
        last=(e,l)
    else:
        if last!=None:
            e,l=last
            gs+=[(e-l,e)]
            last=None
        l=0
ans=0
x=(len(gs)>2)*1
if gs:
    ans=gs[0][1]-gs[0][0]+(len(gs)>1)*1
for i in range(len(gs)-1):
    a,b=gs[i]
    c,d=gs[i+1]
    ans=max(ans,b-a+1,d-c+1)
    if b+1==c:
        ans=max(ans,b-a+d-c+x)
print(ans)