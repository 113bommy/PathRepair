k , n, s, p = map(int, input().split())

a= n/s
if int(a)<a:
    a= int(a+1)
    
a= a*k/p

if int(a)<a:
    a= int(a+1)


print(int(a))

