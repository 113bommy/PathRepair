N = int(input())
flag = sum([i+j==N for i in range(0,N+1,4) for j in range(0,N+1,7)])
print("Yes" if flag>0 else "No")