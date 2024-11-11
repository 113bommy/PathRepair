na,ma = map(int,input().split())
a1 = []
b1 = []
for i in range(na):
    k = list(input())
    for j,c in enumerate(k):
      if c == '1':
        a1.append([i,j])

nb,mb = map(int,input().split())
for i in range(nb):
    k =  list(input())
    for j,c in enumerate(k):
      if c == '1':
        b1.append([i,int(j)])

hash = []
# print(len(a1),len(b1))
max = 0

count = 0

for i in range(100):
    hash.append([0]*100)
for i in a1:
    for j in b1:
        # try:
        #     hash[j[0] - i[0],j[1] - i[1]]
        # except:
        #     hash[j[0] - i[0],j[1] - i[1]] = 1
        #     if hash[j[0] - i[0],j[1] - i[1]] > max:
        #         x,y = j[0] - i[0],j[1] - i[1]
        #         max = hash[j[0] - i[0],j[1] - i[1]]
        # else:
            hash[j[0] - i[0]][j[1] - i[1]]+=1
            if hash[j[0] - i[0]][j[1] - i[1]] > max:
                x,y = j[0] - i[0],j[1] - i[1]
                max = hash[j[0] - i[0]][j[1] - i[1]]
            count+=1

# print(x,y)

print(x,y)