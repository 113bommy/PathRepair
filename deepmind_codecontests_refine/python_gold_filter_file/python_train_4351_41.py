a1,a2,a3,_,*b = [i.split() for i in open(0)]
bingo = [[0, 1, 2], [3, 4, 5], [6, 7, 8], [2, 5, 8], [0, 3, 6], [1, 4, 7], [0, 4, 8], [2, 4, 6]]
s = ["" if i in sum(b,[]) else i for i in a1 + a2 + a3]
for i,j,k in bingo:
    if {s[i],s[j],s[k]} ==  {''}:
        print('Yes')
        exit()
print('No')