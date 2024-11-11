n=int(input())
count=0
for i in range(0,n):
    s=input()
    if(s.count('1')>=2):
        count+=1
print(count)
