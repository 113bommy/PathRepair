h,w = map(int,input().split())
l=[str(input()) for i in range(h)]
p="#"
print(p*(w+2))
for j in l:
    print(p+j+p)
print(p*(w+2))