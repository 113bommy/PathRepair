s=sum(list(map(int,input().split())))
if s%5==0 and s!=0:
    print(s//5)
else:
    print('-1')