k,l,m,n,d=[int(input())for i in' '*5]
for i in range(1,d+1):d-=all((i%k,i%l,i%m,i%n))
print(d)