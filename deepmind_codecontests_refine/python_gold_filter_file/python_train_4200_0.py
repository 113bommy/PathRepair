# n, m, x and y = so linh, so ao vest, so chi so kieu cang
# comfortable  [ai - x , ai + y]
# second a
# third b

# if bj thuoc [ai-x, ai+y] => count++, luu (i,j)
# if ai - x > bj => j++
# if ai + y < bj => i++
# i = 0; j = 0  

#read file
# fname = 'D:\Study-Algorithm-\A_testcase.txt'
# with open(fname) as f:
#     content = f.readlines()
# content = [x.strip() for x in content]   
# n,m,x,y = [int(x) for x in content[0].split(" ")] 
# a = [int(x) for x in content[1].split(" ")] 
# b = [int(x) for x in content[2].split(" ")] 

#read input
n,m,x,y = [int(x) for x in input().split()]
a = [int(x) for x in input().split()]
b = [int(x) for x in input().split()]

i,j = 0,0
saved = []
while (i < n and j < m):
    #print(i,j,a[i],b[j])
    if (a[i] - x <= b[j] and b[j] <= a[i] + y):
        saved.append([i,j])
        #print(i+1,j+1)
        i = i + 1
        j = j + 1
    elif (a[i] + y < b[j]):
        i = i + 1
    elif (a[i] - x > b[j]):
        j = j + 1
    #print(i,j)
print(len(saved))
for i,j in saved:
    print(i+1,j+1)


        
        

