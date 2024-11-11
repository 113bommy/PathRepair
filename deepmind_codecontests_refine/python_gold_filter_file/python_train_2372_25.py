n=int(input())
s=input()

cnt=s.count('R')*s.count('G')*s.count('B')
for i in range(n-2):
    for j in range(i+1,n-1):
        k=2*j-i
        if j<k<n:
            if s[i]!=s[j] and s[j]!=s[k] and s[k]!=s[i]:
                cnt-=1
print(cnt)
