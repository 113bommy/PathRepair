a = input()
for x in range(int(a)):
    b = input().split(" ")
    grid = []
    list = []
    for i in range(int(b[0])):
        grid.append([])
        c = input()
        for j in range(int(b[1])):
            grid[i].append(c[j])
            if(grid[i][j]=="G"):
                list.append([i,j])
    ans = 0
    for i in range(len(grid)):
        for j in range(len(grid[0])):
            if(grid[i][j]=="B"):
                if(i+1<len(grid)):
                    if(grid[i+1][j]=="G"):
                        ans = 1
                    elif(grid[i+1][j]!="B"):
                        grid[i+1][j] = "#"
                if(i-1>=0):
                    if(grid[i-1][j]=="G"):
                        ans = 1
                    elif(grid[i-1][j]!="B"):
                        grid[i-1][j] = "#"
                if(j+1<len(grid[0])):
                    if(grid[i][j+1]=="G"):
                        ans = 1
                    elif(grid[i][j+1]!="B"):
                        grid[i][j+1] = "#"
                if(j-1>=0):
                    if(grid[i][j-1]=="G"):
                        ans = 1
                    elif(grid[i][j-1]!="B"):
                        grid[i][j-1] = "#"
    if(ans==1):
        print("No")
    else:
        dict = {}
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                tag = 0
                if(grid[i][j]=="G" or grid[i][j]=="."):
                    l=-1
                    q=-1
                    if(i-1>=0):
                        if(grid[i-1][j]!="#"):
                            l = grid[i-1][j]
                    if(j-1>=0):
                        if(grid[i][j-1]!="#"):
                            q = grid[i][j-1]
                    if(l!=-1):
                        grid[i][j] = l
                        dict[l].append([i,j])
                        if(q!=-1):
                            if(q!=l):
                                dict[l]+=dict[q]    
                                for k in dict[q]:
                                    grid[k[0]][k[1]] = l
                    elif(q!=-1):
                        grid[i][j] = q
                        dict[q].append([i,j])
                    else:
                        grid[i][j] = i*len(grid[0])+j
                        dict[i*len(grid[0])+j] = [[i,j]]
        ans = 0
        for i in list:
            if(grid[int(b[0])-1][int(b[1])-1]==grid[i[0]][i[1]]):
                ans+=1
            else:
                break
        if(ans==len(list)):
            print("Yes")
        else:
            print("No")