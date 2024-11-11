n=int(input())
a=['']
for i in range(3,n+1):
 if i%3==0:a.append(i)
 elif '3' in list(str(i)):a.append(i)
print(*a)