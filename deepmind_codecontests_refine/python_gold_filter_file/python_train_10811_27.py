n=int(input())
s=input()
ans=[0]
for i in range(len(s)):
    ans.append(s[:i+1].count("I")-s[:i+1].count("D"))
print(max(ans))