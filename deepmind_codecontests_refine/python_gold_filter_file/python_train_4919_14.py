import sys
n,s=map(int,sys.stdin.readline().split())
if(n*2<=s):
    print('YES')
    st=1
    ans=[]
    while(st<n):
        print(2,end=' ')
        st+=1
    print(s-(n-1)*2)
    print(1)
    


else:
    print('NO')
