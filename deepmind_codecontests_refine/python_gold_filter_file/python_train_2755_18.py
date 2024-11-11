"""""""""""""""""""""""""""""""""""""""""""""
|    author: mr.math - Hakimov Rahimjon     |
|    e-mail: mr.math0777@gmail.com          |
"""""""""""""""""""""""""""""""""""""""""""""
#inp = open("lepus.in", "r"); input = inp.readline; out = open("lepus.out", "w"); print = out.write
TN = 1


# ===========================================

  
def solution():
    n = int(input())
    a = list(map(int, input().split()))
    ans = []
    for i in range(1, n-1):
        b = a[:i]+a[i+1:]
        l = []
        for j in range(n-2):
            l.append(b[j+1]-b[j])
        ans.append(max(l))
    print(min(ans))
    
    


# ===========================================
while TN != 0:
    solution()
    TN -= 1
# ===========================================
#inp.close()
#out.close()