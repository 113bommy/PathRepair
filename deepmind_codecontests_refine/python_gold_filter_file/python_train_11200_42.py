number=int(input())
answer=0
for n in range(number):
    sentens=input()
    if sentens=="Tetrahedron":
        answer+=4
    elif sentens=="Cube":
        answer+=6
    elif sentens=="Octahedron":
        answer+=8
    elif sentens=="Dodecahedron":
        answer+=12
    else:
        answer+=20
print(answer)
