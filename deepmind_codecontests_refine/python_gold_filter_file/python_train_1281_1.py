liste=[]
i=0
i2=0
distance=[]
answer='YES'

for _ in range(4):
    x1,y1,x2,y2=map(int,input().split(" "))
    liste.append([(x1,y1),(x2,y2)])


def perpendiculaire(vect1,vect2):
    return vect1[0]*vect2[0]+vect1[1]*vect2[1]
def search(liste,point,excluded_index):
    for i in range(4):
        if point in liste[i] and i!=excluded_index:
            return i,liste[i].index(point)
    return -1,-1

index,i=0,0
for _ in range(4):
    element=liste[index]
    (x1,y1),(x2,y2)=element[i],element[1-i]
    vector1=(x2-x1,y2-y1)
    distance.append(abs(x2-x1)+abs(y2-y1))

    index,i=search(liste,(x2,y2),index)
    if index==-1:
        answer='NO'
        break
    element=liste[index]
    (x1,y1),(x2,y2)=element[i],element[1-i]
    vector2=(x2-x1,y2-y1)

    if perpendiculaire(vector1,vector2)!=0 or 0 not in vector1 or 0 not in vector2 or vector1==(0,0) or vector2==(0,0):
        answer='NO'
        break

if answer=='YES':
    if distance[0]!=distance[2] or distance[1]!=distance[3]:
        answer='NO'

print(answer)