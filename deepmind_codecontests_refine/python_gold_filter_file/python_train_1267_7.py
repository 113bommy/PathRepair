import sys
# n=int(sys.stdin.readline())
n,x,y=list(map(int,sys.stdin.readline().strip().split()))
a=list(map(int,sys.stdin.readline().strip().split()))
a=[10**9+1]*x+a+[10**9+1]*y
# print(a)
for i in range(x,len(a)-y+1):
    # print(a[i])
    if(a[i]==min(a[i-x:i+1]) and a[i]==min(a[i:i+y+1])):
        print(i-x+1)
        # print(a[i])
        break
 