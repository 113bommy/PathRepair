k = int(input())
if k%2 == 0:
    print(int(k/2))
    string = ""
    for i in range(int(k/2)):
        string += "2 "
    print(string[:-1])
else:
    print(int((k-1)/2))
    string = ""
    for i in range(int((k-3)/2)):
        string += "2 "
    print(string+"3")
