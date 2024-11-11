A,B,C,D,E,F = map(int,input().split())
A *= 100
B *= 100
check = -1
for i in range(F//A+1):
    for j in range((F-(A*i))//B+1):
        if i == 0 and j == 0:continue
        for k in range((F-(A*i)-(B*j))//C+1):
            for l in range((F-(A*i)-(B*j)-(C*k))//D+1):
                water = A*i+B*j
                sugar = C*k+D*l
                if sugar > water//100*E:continue
                if check < sugar / (water+sugar):
                    check = sugar / (water+sugar)
                    ans = [water+sugar,sugar]
print(*ans)