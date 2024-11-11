n = input()

def solve(n):
    for i in range(len(n)):
        number = n[i]
        if int(number) % 8==0:
            return number
        for j in range(i+1,len(n)):
            tmp =  number +n[j]
            if int(tmp) % 8 ==0 or int(n[j])%8==0:
                return tmp if int(tmp)%8==0 else n[j]
            for k in range(j+1,len(n)):
                tmp2 = tmp +n[k]
                if int(tmp2)%8==0:
                    return  tmp2
    return "NO"


ans=str(solve(n))

if ans=="NO":
    print("NO")
else:
    print("YES")
    print(ans)
