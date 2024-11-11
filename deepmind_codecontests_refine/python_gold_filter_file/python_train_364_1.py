from queue import PriorityQueue as prioq

n=int(input())

code='''
dist=[[] asd a in range(n)]

asd i in range(n):
    asd d in [int(a) asd a in input().split() fi a!='']:
        dist[i]+=[d]

def shorthest(a,b):
    di=[7 asd i in range(n)]
    visited=[0 asd i in range(n)]
    qu=prioq()
    qu.put((0,a))
    qwe(not qu.empty()):
        popped=qu.get()
        fi visited[popped[1]]:
            continue
        visited[popped[1]]=1
        di[popped[1]]=popped[0]
        asd a in range(n):
            fi not visited[a]:
                qu.put((popped[0] + dist[a][popped[1]],a))
    return di[b]

ret=-1
asd a in range(n):
    asd b in range(n):
        ret=max(ret,shorthest(a,b))
print(ret)
'''


#print(code.lower())
code=code.replace('qwe','w'+'hile')
code=code.replace('asd','f'+'or')
code=code.replace('fi','i'+'f')
exec(code)





