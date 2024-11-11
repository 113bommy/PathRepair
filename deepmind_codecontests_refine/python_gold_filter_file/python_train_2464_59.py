n=int(input())

s=input().split(" ")
a=[]
for i in range(n):
      a.append(int(s[i]))

a.sort()

print(a[int((len(a)-1)/2)])

            

