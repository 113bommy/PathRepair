
import sys

alp = "abcdefghijklmnopqrstuvwxyz"
D = {}
for i in range(26):
    D[alp[i]] = i 


N = int(input())

c = [{}]
num = [N]
dep = [0]

Slis = []
lon = 0


for loop in range(N):

    S = input()
    S += " "
    Slis.append(S)
    #Slen += len(S)

    nind = 0

    for i in S:

        if i not in c[nind]:
            lon += 1
            if len(c[nind]) == 1:
                lon -= 1
            c[nind][i] = len(c)
            c.append({})
            num.append(0)
            dep.append(dep[nind]+1)


        nind = c[nind][i]
        num[nind] += 1

Q = int(input())
#print (lon)

if lon < 70000:

    always = [0] * N
    table = []

    #print (c)
    #print (num)

    #table構築
    for loop in range(N):

        nt = [[0] * 26 for i in range(26)]
        nind = 0

        for i in Slis[loop]:

            if i == " ":
                continue

            #print ("now char",i)

            for j in c[nind]:
                #print ("nowj",j)
                if j == " ":
                    always[loop] += 1
                    #print ("always pl+1")
                elif j != i:
                    #print ("if",i,">",j,"plus:",num[c[nind][j]])
                    nt[D[i]][D[j]] += num[c[nind][j]]

            nind = c[nind][i]

        table.append(nt)

    #print (always)
    #print (table[0])

    #Q = int(input())

    for loop in range(Q):

        k,p = input().split()
        k = int(k)
        k-=1
    
        ans = always[k] + 1

        for i in range(26):
            for j in range(i):

                ind1 = D[p[i]]
                ind2 = D[p[j]]

                ans += table[k][ind1][ind2]

        print (ans)

    sys.exit()




#print (c)
#print (num)


lpc = 0

for loop in range(Q):

    k,p = input().split()
    k = int(k)

    p = " " + p
    nind = 0
    ans = 0

    ncr = 0

    while ncr < len(Slis[k-1]):

        i = Slis[k-1][ncr]

        for j in p:
            if j == i:
                break
            
            elif j in c[nind]:
                ans += num[c[nind][j]]

        while len( c[c[nind][i]] ) == 1:
            for x in c[c[nind][i]]:
                c[nind][i] = c[c[nind][i]][x]
            
        nind = c[nind][i]
        ncr = dep[nind]

    print (ans+1)

