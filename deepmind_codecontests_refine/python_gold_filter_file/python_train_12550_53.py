a,b = map(int, input().split())
mat = input().split()
for i in range(a):
    mat[i]=int(mat[i])
result = 1
for i in range(1,a):
    if mat[a-i]-mat[a-i-1]>b:
        break
    result+=1
print(result)
