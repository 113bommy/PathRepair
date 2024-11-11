n = int(input())
##a = "Icosahedron"
##b = "Cube"
##c = "Tetrahedron"
##d = "Dodecahedron"

dic = {"Icosahedron":20,
"Cube":6,
"Octahedron":8,
"Tetrahedron":4,
"Dodecahedron":12}

res = 0
for i in range(n):
    x = str(input())
    res += dic[x]
    
    
print(res)
