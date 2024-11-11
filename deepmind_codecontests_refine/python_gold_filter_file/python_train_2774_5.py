n,k=map(int,input().split())
list=[int(i) for i in input().split()]
temp=[]
for i in range(k):
    temp.append(n%list[i])
small,i=min(temp),0
while(i<k):
    if(small==temp[i]):
        break
    i+=1
print(i+1,int(n//list[i]))