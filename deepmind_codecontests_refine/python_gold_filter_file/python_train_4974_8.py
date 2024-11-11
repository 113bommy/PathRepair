ans = [1]*365
for i in range(365):
    ans[i]=i%25 + 2
for i in range(365):
    print(ans[i])