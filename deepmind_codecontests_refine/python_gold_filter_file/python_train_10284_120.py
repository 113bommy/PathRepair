K=int(input())
A,B=(int(x) for x in input().split())
if K-(A%K)<=B-A or A%K==0:print('OK')
else:print('NG')
