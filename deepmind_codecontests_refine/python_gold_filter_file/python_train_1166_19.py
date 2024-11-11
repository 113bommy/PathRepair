inp=[]
for _ in range(6):
    inp.append(int(input()))
a,b,c,d,e,f=inp[0],inp[1],inp[2],inp[3],inp[4],inp[5]
if e>f:
    print(e*min(a,d) + f*min(min(b,c),d-min(a,d)))
else:
    print(f*min(min(b,c),d) + e*min(a,d-min(min(b,c),d)))