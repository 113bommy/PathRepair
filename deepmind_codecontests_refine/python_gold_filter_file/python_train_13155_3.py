n = int(input())

white, black = [], []

for i in range(n):
    color, weightSum = map(int, input().split())
    if color == 0:
        white.append([weightSum, i+1])
    else :
        black.append([weightSum, i+1])

white.sort()
black.sort()

wc,bc, wl, bl, edges = 0 , 0, len(white), len(black), []

while wc < wl and bc < bl:
    weight = white[wc][0] - black[bc][0]
    edges.append([white[wc][1], black[bc][1], min(white[wc][0], black[bc][0])])
    #print([ wc, bc ,white[wc][1], black[bc][1], min(white[wc][0], black[bc][0])])
    if weight > 0 or (weight == 0 and wl - wc < bl - bc):
        white[wc][0]-= black[bc][0]
        bc += 1
    else:
        black[bc][0] -= white[wc][0]
        wc+=1
    #print([wc, bc])
print("\n".join(map("{0[0]} {0[1]} {0[2]}".format, edges)))
