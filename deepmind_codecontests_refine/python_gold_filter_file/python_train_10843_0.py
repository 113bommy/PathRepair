q = int(input())

powers = [1]
for i in range(50):
    powers.append(powers[-1]*2)
    
for _ in range(q):
    a,b,m = [int(x) for x in input().split()]
    if a == b:
        print(1,a)
    else:
        if m == 1:
            good = False
            for r in range(50):
                if powers[r]*(a+1) > b:
                    break
                else:
                    if powers[r]*(a+1) == b:
                        good = True
                        power = r
                        break
            if good:
                print(power+2, end = ' ')
                print(a,end= ' ')
                for j in range(r):
                    print((a+1)*powers[j], end = ' ')
                print((a+1)*powers[r])
                    
            else:
                print(-1)
        else:
            terms = 0
            for r in range(50):
                if powers[r]*(a+1) > b:
                    break
                else:
                    if powers[r]*(a+m) >= b:
                        terms = r+2
                        break
                
            if terms == 0:
                print(-1)
            else:
                components = terms-1
                p = components-1
                X = b-powers[p]*a
                C = [0]
                for q in range(components):
                    if q != components-1:
                        C.append(min(X//powers[p-q-1],m))
                        X -= powers[p-q-1]*C[-1]
                        if q < components-1 and X < powers[p-q-1]:
                            X += powers[p-q-1]
                            C[-1] -= 1
                    else:
                        C.append(X)
                    
                T = [a,a+C[1]]
                for l in range(1,components):
                    T.append(T[-1]*2+C[l+1]-C[l])
                print(terms, end = ' ' )
                for e in T:
                    if e != T[-1]:
                        print(e,end = ' ')
                    else:
                        print(e)