a,b,c,n=map(int ,input().split())
no=a+b-c
if n<=no or c>b or c>a  :
    print("-1")
else:
    print(n-no)