N = int(input())
protokol = input().lower()
protokol = list(protokol)
#protokol.append(protokol[len(protokol)-1])
#print(protokol)
t_pr = []
k = 0

for i in range(len(protokol)):
    if not protokol[i] in t_pr and (len(t_pr) != 2):
        t_pr.append(protokol[i])

    if len(t_pr) == 2 and ((t_pr[0] == 'r' and t_pr[1] == 'l') or (t_pr[0] == 'l' and t_pr[1] == 'r') or (t_pr[0] == 'u' and t_pr[1] == 'd') or (t_pr[0] == 'd' and t_pr[1] == 'u')):
        k = k + 1
        #print(t_pr)
        t_pr = []
        t_pr.append(protokol[i])
    elif len(t_pr) == 2 and (not protokol[i] in t_pr):
        k = k + 1
        #print(t_pr)
        t_pr = []
        t_pr.append(protokol[i])

print(k+1)

