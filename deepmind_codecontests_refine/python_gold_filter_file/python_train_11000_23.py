n=int(input())
bills=[100,20,10,5,1]
count=0
for i in bills:
    count+=n//i
    n=n-(n//i)*i
print(count)