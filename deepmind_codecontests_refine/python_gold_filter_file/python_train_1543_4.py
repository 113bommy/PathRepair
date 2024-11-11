sn,bn=map(int,input().split(" "))
fu=[int(sn*(sn-1)/2)]
gr_si=[n for n in range(sn+1)]
siL_gr=[[n] for n in range(sn+1)]
siL_br=[]
for _ in range(bn):
    siL_br.append(list(map(int, input().split(" "))))
siL_br=siL_br[::-1]

for bri in range(bn-1):
    si1,si2=siL_br[bri]
    gr1 = gr_si[si1]
    gr2 = gr_si[si2]
    if gr1==gr2:
        fu.append(fu[bri])
    else:
        lengr1 = len(siL_gr[gr1])
        lengr2 = len(siL_gr[gr2])
        if lengr1<lengr2:
            gr1,gr2=gr2,gr1
        fu.append(fu[bri]-lengr1*lengr2)
        for si in siL_gr[gr2]:
            gr_si[si]=gr1
        siL_gr[gr1]+=siL_gr[gr2]
        siL_gr[gr2]=[]

print(*fu[::-1],sep="\n")