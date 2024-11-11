n=int(input())
s=input()
w_cnt=s.count(".")

ans=[w_cnt]
b=0
w=w_cnt

for i in range(n):
    if s[i]=="#":
        b+=1
    else:
        w-=1
    ans.append(b+w)

print(min(ans))