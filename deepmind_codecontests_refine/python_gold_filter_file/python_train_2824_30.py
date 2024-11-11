get = lambda : map(int , input().split())
n , l = get()
inp = list(get())
m = 1
ans = 1
for i in range(1 , n):
     if inp[i] == inp[i - 1]:
          m = 1
     else:
          m += 1
     ans = max(ans , m)
print(ans)
