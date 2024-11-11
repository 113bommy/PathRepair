def inint():
    return int(input())
def mp():
    return map(int,input().split())
from bisect import bisect,bisect_left
    
def sol(i,j):
    works=bisect(a,j)-bisect_left(a,i)
    if works==0:return A
    if i==j:return B*works
    m=(i+j)>>1
    return min(B*(j-i+1)*works,sol(i,m)+sol(m+1,j))    
    
n,k,A,B=mp()
a=list(mp())
a.sort()
#print(a)
print(sol(1,2**n))
