a = input()
mod = 1000000007
ans = 0
count_a = 0
for i in a:
    if i=='a':
        count_a+=1
    else:
        ans+= (pow(2,count_a,mod)-1)%mod
print(ans%mod)
