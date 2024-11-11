total = int(input())
color = input()
mode = ['RGB','RBG','BRG','BGR','GBR','GRB']
cnt = [0,0,0,0,0,0]
_max = len(color)
def haveSame(a,b):
    result = 0
    assert type(a) is str
    assert type(b) is str
    for i in range(0, min(len(a),len(b)) ):
        if a[i]==b[i]: result+=1
    return result
for i in range(0,len(color),3):
    for j in range(0,6):
        cnt[j] += haveSame(mode[j],color[i:i+3])
        #print(i,' ',j,' ',cnt[j])
maxcnt = [cnt[0],0]
for i in range(1,6):
    if cnt[i] > maxcnt[0]:
        maxcnt = [cnt[i],i]

print(total - maxcnt[0])
if maxcnt[0] == 0:print(color)
else:print((mode[maxcnt[1]]
    *(total//3+1))[:total])    