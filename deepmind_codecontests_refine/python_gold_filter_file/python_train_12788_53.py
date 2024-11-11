A,B,C,D,E,F = map(int,input().split())

water,sugar = -1,-1
t = 0
for i in range(31):
    for j in range(31):
        for p in range(F//C):
            for q in range(F//D):
                k = i*A + j*B
                pq = p*C + q*D
                if k == 0:
                    break

                if k*100 + pq > F:
                    break

                if k*E >= pq:
                    if t <= (100*pq)/(100*k + pq):
                        t = (100*pq)/(100*k + pq)
                        water,sugar = 100*k+pq,pq

print(water,sugar)
