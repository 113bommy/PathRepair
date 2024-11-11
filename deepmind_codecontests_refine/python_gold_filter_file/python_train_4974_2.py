ans = [1]*365
for i in range(365):
    ans[i]=i%26 + 1

for i in range(200,250):
    ans[i]=i%52 //2 + 1

for i in range(365):
    print(ans[i])