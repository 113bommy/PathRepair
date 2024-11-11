a=int(input())


t=list(map(int,input().split()))
s=list(map(int,input().split()))




if sum(t)>=sum(s):
    print('Yes')
else:
    print('No')