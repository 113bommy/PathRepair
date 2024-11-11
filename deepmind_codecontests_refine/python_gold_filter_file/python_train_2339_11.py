F = input()
M = input()
S = input()
choices = [F,M,S]
winner = ['F','M','S']
scissor = 'scissors'
paper = 'paper'
rock = 'rock'
if choices.count(paper) == 2 and choices.count(scissor) == 1:
    print(winner[choices.index(scissor)])
elif choices.count(rock) == 2 and choices.count(paper) == 1:
    print(winner[choices.index(paper)])
elif choices.count(scissor) == 2 and choices.count(rock) == 1:
    print(winner[choices.index(rock)])
else:
    print('?')