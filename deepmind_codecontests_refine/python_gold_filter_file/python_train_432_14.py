n=int(input())
A=list(int(i) for i in input().split(" "))
#n=6
#A=[2,9]
A.sort()
max=A[-1]
stolenguns=0
B=[]
for i in range(n-1):
    ele=max-A[i]
    stolenguns+=ele
    B.append(ele)
def gcd(x,y):
    while(y):
        x,y=y,x%y
    return x
if(n>2):
    g=gcd(B[0],B[1])
else:
    g=B[0]
for i in range(2,n-1):
    g=gcd(g,B[i])
print(stolenguns//g,g)
