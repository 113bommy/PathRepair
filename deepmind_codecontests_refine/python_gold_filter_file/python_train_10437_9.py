z=input;
for _ in range(int(z())):
    z();l,k,p=list(map(int,z().split())),-1,[]
    for j in l:p.append(abs(j)*k);k*=-1
    print(*p)
