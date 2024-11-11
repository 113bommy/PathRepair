if __name__ == "__main__":
    numberofRecipes, min_numberofRecipes, numberofQuestions = map(int, input().split())

    recipes = [0] * 200009

    # partial sum array
    for i in range(numberofRecipes):
        low, high = map(int, input().split())
        recipes[low] += 1
        recipes[high+1] -= 1


    # print(recipes[91:101])
    # index:  [91, 92, 93, 94, 95, 96, 97, 98, 99, 100]
    # output: [ 1,  1,  0,  0, -1,  0,  1, -1,  0,  -1]

    # prefix sum array
    for i in range(1,len(recipes)):
        recipes[i] += recipes[i-1]

    # print(recipes[91:101])
    # index:  [91, 92, 93, 94, 95, 96, 97, 98, 99, 100]
    # output: [ 1,  2,  2,  2,  1,  1,  2,  1,  1,   0]
 
 
    for i in range(1, len(recipes)):
        if recipes[i] >= min_numberofRecipes:
            recipes[i] = 1 + recipes[i-1]
        else:
            recipes[i] = recipes[i-1]
    
    for i in range(numberofQuestions):
        a, b = map(int,input().split())
        print(recipes[b] - recipes[a-1])