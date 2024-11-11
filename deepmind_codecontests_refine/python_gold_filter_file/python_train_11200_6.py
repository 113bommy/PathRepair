import sys

t = int(sys.stdin.readline())

shapes = ['Tetrahedron\n', 'Cube\n','Octahedron\n','Dodecahedron\n', 'Icosahedron\n']
face = [4,6,8,12,20]

res = 0

for i in range(0,t):
    s = str(sys.stdin.readline())
    #print(s)
    for j in range(0,5):
        #print(shapes[j])
        #print(s)
        if s == shapes[j]:
            #print("hi")
            res += face[j]

print(res)
