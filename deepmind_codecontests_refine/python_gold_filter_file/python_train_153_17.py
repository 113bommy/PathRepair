import sys
trafic = 0
s = set()
for request in sys.__stdin__:
    if request[0] == "+":
        s.add(request[1:])
    elif request[0] == "-":
        s.remove(request[1:])
    else:
        trafic += len(request[request.find(":")+1:-1])*len(s)
print(trafic)