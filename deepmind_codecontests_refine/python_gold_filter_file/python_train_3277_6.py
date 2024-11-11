s = [""]+list(input())
n = int(input())
n = len(s)
l = n * [0]
for q in map(int, input().split()):
    l[q]+=1
for i in range(1,n//2+1):
    l[i]+=l[i-1]
    if l[i] & 1:
        s[i], s[n-i] = s[n-i], s[i]
print("".join(s))