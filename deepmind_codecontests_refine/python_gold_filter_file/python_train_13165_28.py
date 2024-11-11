n = list(input())
#print(n)
lis=[0]*(10)
lis[0]=2;lis[1]=7;lis[2]=2;lis[3]=3
lis[4]=3;lis[5]=4;lis[6]=2;lis[7]=5
lis[8]=1;lis[9]=2
ans=1
for i in n:
    ans*=(lis[int(i)])
print(ans)    
