n_child = int(input())
take = input().split(' ')
countone = take.count('1')
counttwo = take.count('2')
countthree = take.count('3')
max_teams = min(countone,counttwo,countthree)
print (max_teams)
for i in range(max_teams):
    one = take.index('1')
    two = take.index('2')
    three = take.index('3')
    team = [one,two,three]
    take[one] = ""
    take[two] = ""
    take[three] = ""
    print (one+1,two+1,three+1)
