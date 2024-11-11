n=int(input())+1
c=0
for i in range(1,n):
    if i%3!=0 and i%5!=0:
        c+=i
print(c)