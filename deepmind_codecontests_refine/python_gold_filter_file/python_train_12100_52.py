lines = int(input())
#0+2x == 10-3y
#x = e - s / a + b


for line in range(lines):
    l = list(map(int,input().split()))
    s,e,a,b = l[0],l[1],l[2],l[3]
    x = (e - s) / (a + b) 
    if x%2 == 0 or x%2 == 1:
       print(int(x))
    else:
       print(-1)            
#     string = str(input()).split(" ")
#     count = 0
#     while int(string[1]) > int(string[0]):
#         string[0] = int(string[0]) + int(string[2]) 
#         string[1] = int(string[1]) - int(string[3])
#         count = count + 1
#         i = int(string[1]) - int(string[3])
#         if string[0] == string[1]:
#             print(count)
#             break
#         elif string[1] < string[0]:
#             count = -1
#             print(count) 
#             break
            
        
