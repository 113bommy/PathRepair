from collections import defaultdict, deque
if __name__ == "__main__":
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))

    graph = defaultdict(list)
    inorder = defaultdict(int)
    value = defaultdict(int)
    for i in range(n):
        value[i] = a[i]
        if(b[i]!=-1):
            graph[i].append(b[i]-1)
            inorder[b[i]-1] += 1
    
    q = deque()
    for i in range(n):
        if(inorder[i]==0):
            q.append(i)
    #print(q)
    stack = []
    neg_val = []
    while(q):
        current_node = q.popleft()
        if(value[current_node]>=0):
            stack.append(current_node)
        elif(value[current_node]<0):
            neg_val.append(current_node)
        for i in graph[current_node]:
            if(value[current_node]>0):
                value[i] += value[current_node]
            inorder[i] -= 1
            if(inorder[i]==0):
                q.append(i)

    
    # for i in range(n):
    #     current_node = stack[i]
    #     if(value[current_node]>0):
    #         for j in graph[current_node]:
    #             value[j] += value[current_node]
    #     elif(value[current_node]<0):
    #         neg_val.append(current_node)

    print(sum(value.values()))
    print(*[i+1 for i in (stack+neg_val[::-1])])

    

