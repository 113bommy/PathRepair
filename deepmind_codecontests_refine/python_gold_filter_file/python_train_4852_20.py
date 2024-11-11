mod = 1000000007
ii = lambda : int(input())
si = lambda : input()
dgl = lambda : list(map(int, input()))
f = lambda : map(int, input().split())
il = lambda : list(map(int, input().split()))
ls = lambda : list(input())
n, a=f()
int_ang=((n-2)*180)/n
int_ang=(180-int_ang)/2
mn=abs(a-int_ang)
vtx=3
for i in range(3,n+1):
    if mn>abs(a-(int_ang*(i-2))):
        mn=abs(a-int_ang*(i-2))
        vtx=i
print(2,1,vtx)