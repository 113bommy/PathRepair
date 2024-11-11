n=int(input())
R=[list(input().split()) + [i+1] for i in range(n)]
R.sort(key=lambda x: (x[0],-int(x[1])))
for r in R:
    print(r[2])